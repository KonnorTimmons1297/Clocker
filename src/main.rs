mod config;
mod punch;

use clap::{App, Arg};
use chrono::Local;
use config::Config;
use punch::*;

const CONFIG_FILE_NAME : &str = ".config";

const APP_NAME : &str = "Clocker";
const VERSION : &str = "1.0";
const DESCRIPTION : &str = "Employee time management utility";

const ARG_ACTION : &str = "action";
const ARG_ACTION_HELP : &str = "Specify whether you wish to clock in or out";
const ARG_ACTION_VALUE_NAME : &str = "in/out";
const ACTION_PUNCH_IN : &str = "in";
const ACTION_PUNCH_OUT : &str = "out";

fn main() {
    let args = App::new(APP_NAME)
        .version(VERSION)
        .author("Konnor Timmons <konnortimmons@gmail.com>")
        .about(DESCRIPTION)
        .arg(
            Arg::with_name(ARG_ACTION)
                .value_name(ARG_ACTION_VALUE_NAME)
                .help(ARG_ACTION_HELP)
                .required(true)
        )
        .get_matches();
    
    match args.value_of(ARG_ACTION) {
        Some(command) => {
            let action = match command {
                ACTION_PUNCH_IN => ClockAction::In,
                ACTION_PUNCH_OUT => ClockAction::Out,
                _ => panic!("Did not expect: {}", command)
            };

            let clock_event = ClockEvent::new(action);
            clock_event.print();

            let mut config = Config::get(CONFIG_FILE_NAME);

            let mut timesheet : TimeSheet = if let Some(timesheet) = config.time_sheets.pop() {
                println!("Found timesheet!");
                timesheet
            } else {
                println!("No timesheet found, creating new one");
                create_new_timesheet()
            };
            
            timesheet.time_card.add_event(clock_event);

            config.time_sheets.push(timesheet);
            config.save();
        }
        None => println!("Specify an action")
    }
}

fn create_new_timesheet() -> TimeSheet {
	TimeSheet::new(Local::now().to_rfc3339())
}