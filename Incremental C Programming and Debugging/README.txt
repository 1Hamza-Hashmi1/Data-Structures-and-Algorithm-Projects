Hamza Hashmi , 501093570 , 1/24/23

The 2 requirments stated in the lab 1 manual have been met. For both reuirments, the code gives the right output. 



Question:

The mySort() function has a signiture of 
mySort(data, nDataItems);

The bestterSort() function has a signiture of
betterSort(int data[], first, last);


To have it where the mySort() can do the same operation as betterSort(), the body of the mySort() method would look like the following:

mySort(int array[], int numOfElements){
	betterSort(array[], 0, numOfElements);
}

This body sets the first index as 0 and uses the numOfElements value as the last index. Thus allowing mySort() to exploit the better sorting function in the supplied object module.
