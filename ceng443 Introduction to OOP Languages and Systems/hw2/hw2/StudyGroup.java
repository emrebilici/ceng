package hw2;

import java.util.concurrent.locks.*;

public class StudyGroup {

	private Lab lab;
	private String name;
	
	public StudyGroup(String name, Lab lab){
		this.lab = lab;
		this.name = name;
	}
	
	public String getName() {
		return name;
	}
	
	public Lab getLab() {
		return lab;
	}
	
	// this comments for me.
	// I could use synchronized statement but how can I use condition then?
	// I should use synchronized in lab, since the lab object can be reachable to one simultaneously.
	// Other studygroups can be study in other labs, so synchronized statement is not proper for here.
	// Lab object should be locked.
	
	
	// This is my mentality and thinking way:
	// While trying monitor in this class, after numbers are zero other thread does not continue.
	// monitors are on the object. So monitor works on the same object. 
	// That is why other thread is suspended in wait.
	// I couldnt handle to signal other object. For example, when the lab is assigned to 'ruleBreakers' 
	// after the lab is empty, any other study group thread dont get signal to wake up.
	// 
	// If we think this problem like consumer producer, our buffer is lab.
	// in that problem buffer has monitor. So in this problem lab can be implemented like monitor.
	// after thinking that I decide to use synchronized block on lab object.
	// 
	
	
	public void startStudyingWith() {
		// It is important to synchronize lab object since lab object keep all students.
		// If we can synchronize lab, it can be prevented that another groups to enter that lab.
		// and when exiting from lab other threads can get signal.
		synchronized (lab) {
			try {
				// while lab is full or unless there is a same group
				// this thread will wait signal from thread that use stopStudying()
				while(this.getLab().checkFull() || this.getName() != this.getLab().getOccupier() ) {
					// In case of empty case.
					if (this.getLab().checkEmpty()) {
						break;
					}
					this.getLab().wait();
				}				
				this.getLab().enterStudent(this.getName());
			}
			catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}
	
	public void stopStudyingWith() {
		synchronized (lab) {
			this.getLab().exitStudent();	
			// after student exit a thread will be notified.
			this.getLab().notify();
		}
	}
	
}
