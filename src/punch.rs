use chrono::prelude::*;
use serde::{Serialize, Deserialize};

#[derive(Serialize, Deserialize, Debug)]
pub enum ClockAction {
	In, 
	Out
}

#[derive(Serialize, Deserialize, Debug)]
pub struct ClockEvent {
    pub action : ClockAction,
    pub time : DateTime<Local>
}

impl ClockEvent {
	pub fn new(action : ClockAction) -> ClockEvent {
		ClockEvent {
			action,
			time : Local::now()
		}
	}
	
    pub fn print(&self) {
        println!("Punch type: {:?}, at time {:?}", self.action, self.time);
    }
}

#[derive(Serialize, Deserialize, Debug)]
pub struct ClockEventRecord {
	pub day : u32,
	pub month : u32,
	pub year : i32,
	pub clock_events : Vec<ClockEvent>
}

impl ClockEventRecord {
	pub fn new() -> ClockEventRecord {
		let today = Local::today();

		ClockEventRecord { 
			day: today.day(),
			month: today.month(),
			year: today.year(), 
			clock_events : Vec::new() 
		}
	}

	pub fn add_event(&mut self, event : ClockEvent) {
		self.clock_events.push(event)
	}
}

#[derive(Serialize, Deserialize, Debug)]
pub struct TimeSheet {
	pub name : String,
	pub time_card : ClockEventRecord
}

impl TimeSheet {
	pub fn new(name : String) -> TimeSheet {
		TimeSheet { name, time_card: ClockEventRecord::new() }
	}
}