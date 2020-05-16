use std::io::{Read, Write};
use std::fs::*;
use serde::{Serialize, Deserialize};
use std::path::Path;
use crate::punch::TimeSheet;

pub const CONFIG_DIR_NAME : &str = ".clocker";

#[derive(Serialize, Deserialize, Debug)]
pub struct Config {
    file_name : String,
    pub time_sheets : Vec<TimeSheet>
}

impl Config {
    pub fn get(file_name : &str) -> Config {
        let path = Self::create_path_str(file_name);
        if !Path::new(&path).exists() {
            Self::create_clocker_directory();
            Config { file_name: String::from(file_name), time_sheets: vec![] }
        } else {
            Self::read_config(file_name)
        }
    }

    pub fn save(&self) {
        self.write_config();
    }

    fn write_config(&self) {
        let path_str = Self::create_path_str(self.file_name.as_str());
        let clocker_config_dir = Path::new(&path_str);
        let mut config_file = File::create(clocker_config_dir).expect("Failed to create config file");
        let config_json = self.to_json();
        config_file.write_all(config_json.as_bytes()).expect("Failed to write config");
    }

    fn create_clocker_directory() {
        if let Err(msg) = create_dir(CONFIG_DIR_NAME) {
            panic!("Failed to create configuration directory: {}", msg)
        }
    }

    fn create_path_str(file_name : &str) -> String {
        let mut string = String::from(CONFIG_DIR_NAME);
        string += "/";
        string += file_name;
        return string;
    }

    fn read_config(file_name : &str) -> Config {
        let path_str = Self::create_path_str(file_name);
        let config_path = Path::new(&path_str);
        let mut config_file = File::open(config_path).expect("Failed to open config file");
        let mut config_contents = String::new();
        config_file.read_to_string(&mut config_contents);
        serde_json::from_str(config_contents.as_str()).expect("Failed to deserialize config")
    }

    fn to_json(&self) -> String {
        String::from(serde_json::to_string(self).expect("Failed to serialize config"))
    }
}