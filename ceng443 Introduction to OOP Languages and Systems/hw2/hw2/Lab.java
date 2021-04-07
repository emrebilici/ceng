package hw2;

import java.util.concurrent.locks.*;

public class Lab {
	
	private Lock lock = new ReentrantLock();
	//public Condition busyLab;
	
	private int capacity;
	private String name;
	private int currentCount;		//this is for checking empty or full
	private String occupier;
	
	public Lab(String name, int capacity) {
		this.capacity = capacity;
		this.name = name;
		this.currentCount = 0;
		this.occupier = "";
	}
	
	public String getName() {
		return name;
	}
	
	public int getCapacity() {
		return capacity;
	}
	
	public void inrCurrentNo() {
		this.currentCount ++;
	}
	
	public void decrCurrentNo() {
		this.currentCount --;
		
	}
	
	public boolean checkFull() {
		if(currentCount == capacity) {
			return true;
		}
		else {
			return false;
		}
	}
	
	public boolean checkEmpty() {
		if(this.currentCount == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	
	public void setOccupier(String occ) {
		this.occupier = occ;	
	}
	
	public String getOccupier() {
		return occupier;
	}
	
	
	
	// This locks for preventing to groups enter or exit same time.
	// this can be unnecessary.
	public void enterStudent(String name) {
		lock.lock();
		try {
			this.inrCurrentNo();
			this.setOccupier(name);
		} 	
		finally {
			lock.unlock();
		}	
	}
	
	public void exitStudent() {
		lock.lock();
		this.decrCurrentNo();
		if(this.checkEmpty()) {
			this.setOccupier("");
		}
		lock.unlock();			

	}
	
}
