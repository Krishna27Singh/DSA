#include <iostream>
using namespace std;

int main() {
	int tc; cin>>tc;
	while(tc--){
	    int a1, b1, a2, b2; cin>>a1>>b1>>a2>>b2;
	    
	    if(a1-a2 == b1-b2) cout<<"YES"<<endl;
	    else if((a1>a2 && b1<b2) || (a1<a2 && b1>b2)){
	        int accumulated_silver_initial = b1 + (a1*5);
	        int accumulated_silver_final = b2 + (a2*5);
	        
	        if(accumulated_silver_final == accumulated_silver_final){
	            cout<<"YES"<<endl;
                cout<<accumulated_silver_final<< " "<<accumulated_silver_initial<<endl;
                cout<<"debug"<<endl;
	            continue;
	        }
	        
	        bool check = false;
	        while(a1>=0 && b1>=0){
	            a1--;
	            b1--;
	            
	            int accumulated_silver_initial = b1 + (a1*5);
	            int accumulated_silver_final = b2 + (a2*5);
	            
	            if(accumulated_silver_final == accumulated_silver_initial){
                    cout<<"debug1"<<endl;
                    cout<<accumulated_silver_final<< " "<<accumulated_silver_initial<<endl;
	                check = true;
	            }
	            
	        }
	        
	        if(check) cout<<"YES"<<endl;
	        else cout<<"NO"<<endl;
	    }
	    else{
	        cout<<"NO"<<endl;
	    }
	    
	}

}
