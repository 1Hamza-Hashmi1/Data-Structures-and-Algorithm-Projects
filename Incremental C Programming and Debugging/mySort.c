void mySort(int d[], unsigned int n)
{
	int j,x;
	
	for(int i = 0; i < n; i++){
		j = i - 1;
		x = d[i];
		while(j>=0 && d[j]>x){
			d[j+1] = d[j];
			j--;
		}
		d[j+1] = x;
	}
}
