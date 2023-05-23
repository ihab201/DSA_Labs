#include <iostream>
#include <ctime>

using namespace std;

long fib(int n){

        if(n <= 1) {
			return n;
		}
		long fib = 1;
		long prevFib = 1;

		for(int i=2; i<n; i++) {
			long temp = fib;
			fib+= prevFib;
			prevFib = temp;
		}
		return fib;
}

long fib_recursive(int n){
    if(n == 0 || n== 1) return n;
    return fib_recursive(n - 1) + fib_recursive(n-2);
}

clock_t start , end ;


int main(){
    long n = 15;
    long result;
    clock_t start; //start time
    clock_t end; //end time

    cout << "Type a number: \n"; 
    cin >> n;

    //recursive
    start  = clock(); 
    result = fib_recursive(n);
    end    = clock(); 
    cout << "feb_recursive of " << n << " is: " << result << "| time taken is: " 
         << ((float)(end - start) / CLOCKS_PER_SEC) << " seconds \n";

    //Non recursive
    start  = clock(); 
    result = fib(n);
    end    = clock();
    cout << "feb of " << n << " is: " << result << "| time taken is: " 
         << ((float)(end - start) / CLOCKS_PER_SEC) << " seconds \n";

    return 0;
}