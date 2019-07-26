#More functionality to be added over time

Note:This library might be used in various projects I have, however it is not being retroactively updated in all previous projects, the version of it used in the project, is within the projects folder

# Tools library

Currently contains:

 -Thread-safe queue(Thread_Safe_Queue<T>)
 
 -Time measurement(Time_Measure)
 
 -Random number generation(Rand_Num_Gen)

Functionality:

Rand_Num_Gen
------------------------
object.randomGenerator(lower_limit, upper_limit), returns a number >= lower_limit and <=upper_limit

Time_Measure - Momentarily a bit clunky since you can't change the unit of measurement in a dynamic way
-----------------------
object.now(), saves a time point inside an array within the class

object.print(step), prints on the console the difference between measurements for every <step> steps, Ex: step=2, 1-0,3-2,4-3,etc
 
object.print(a,b), prints on the console the difference for 2 specific time point logs; bigger-smaller
 
Thread_Safe_Queue<T> - Momentarily not that thread-safe as it still needs a way to know when it should exit in case it gets locked in the checking loop
-----------------------
object.push_back(), adds an item to the back queue
 
object.pop_back(), returns and removes the item from the back of the queue

object.check(), returns the size of the container

object.pop_front(),returns and removes the item from the front of the queue
