#include <iostream>
#include <stack> // stack library 
#include <cmath> // for pow function

using namespace std;

/*    RULES FOR EVEN NUMBER

    1- Source to auxilary
    2- Source to destination
    3- Auxilary to destination

    RULES FOR ODD NUMBER

    1- Source to destination
    2- Source to auxilary
    3- Destination to auxilary
*/

void towersGeneral (stack<int>& destination, int numDisks){  // Destination => Third Peg (result)

stack <int> source;  // First peg 

for (int i = numDisks; i > 0; i--){
source.push(i); // we add disk to source stack
}

stack <int> auxilary; // Second Peg

int steps =pow(2,numDisks)-1; // -formula for the number of steps- How many steps should ?
int iteration; // what step are we on 

if(numDisks%2 == 0){ // If number of disks is even number

    for(iteration=1 ; iteration <= steps ; iteration++){ 
    
    if( iteration%3 == 0 ){ // AUXILIARY TO DESTINATION  Step:3
        
        if(destination.empty()){
            destination.push(auxilary.top()); //I sent top element of auxiliary to destination peg
            auxilary.pop(); //I removed top element of auxiliary 
        }

        else if(auxilary.empty()){
            auxilary.push(destination.top());
            destination.pop();
        }

        else{  // if both are not empty then smaller disk should come top of the big one

            if(destination.top() > auxilary.top()){
                destination.push(auxilary.top());
                auxilary.pop();
            }

            else{ // ( auxilary.top() > destination.top() )
                auxilary.push(destination.top());
                destination.pop();
            }

        }
    } //End of Step 3
    
    if( iteration%3 == 1 ){ // SOURCE TO AUXILIARY  Step:1
        
        if(auxilary.empty()){
            auxilary.push(source.top());
            source.pop();
        }

        else if(source.empty()){
            source.push(auxilary.top());
            auxilary.pop();
        }

        else{ // if both are not empty then smaller disk should come top of the big one
            
            if(auxilary.top() > source.top()){
                auxilary.push(source.top());
                source.pop();
            }

            else{ // ( source.top() > auxilary.top() )
                source.push(auxilary.top());
                auxilary.pop();
            }

        }
    }  // End of Step 1

    if( iteration%3 == 2 ){ // SOURCE TO DESTINATION Step:2

        if(destination.empty()){
            destination.push(source.top());
            source.pop();
        }
        
        else if(source.empty()){
            source.push(destination.top());
            destination.pop();
        }

        else{  // if both are not empty then smaller disk should come top of the big one

            if(destination.top() > source.top()){
                destination.push(source.top());
                source.pop();
            }

            else{ //( source.top() > destination.top() )
                source.push(destination.top());
                destination.pop();
            }

        }
    }// End of Step 2

    } 

} 

else{ //  // If number of disks is odd number
    for(iteration=1 ; iteration <= steps ; iteration++){
        
        if( iteration%3 == 1 ){ // SOURCE TO DESTINATION  Step:1
            
            if(destination.empty()){
                destination.push(source.top()); // //I sent top element of source to destination peg
                source.pop(); //I removed top element of source peg 
            }

            else if(source.empty()){
                source.push(destination.top());
                destination.pop();
            }

            else{  // if both are not empty then smaller disk should come top of the big one

                if(destination.top() > source.top()){
                    destination.push(source.top());
                    source.pop();                   
                }

                else{ // (  source.top() > destination.top() )
                    source.push(destination.top());
                    destination.pop();
                }

            }
        } // End of Step 1

        if( iteration%3 == 2 ){ // SOURCE TO AUXILARY Step:2
            
            if(auxilary.empty()){
                auxilary.push(source.top());
                source.pop();
            }

            else if(source.empty()){
                source.push(auxilary.top());
                auxilary.pop();
            }

            else{  // if both are not empty then smaller disk should come top of the big one
               
                if(auxilary.top() > source.top()){
                    auxilary.push(source.top());
                    source.pop();
                }

                else{ // ( source.top() > auxilary.top() )
                    source.push(auxilary.top());
                    auxilary.pop();
                }

            }
        } // End of Step 2

        if(iteration%3 == 0){ // DESTINATION TO AUXILARY Step:3

            if(auxilary.empty()){
                auxilary.push(destination.top());
                destination.pop();
            }

            else if(destination.empty()){
                destination.push(auxilary.top());
                auxilary.pop();
            }

            else{ // if both are not empty then smaller disk should come top of the big one

                if(auxilary.top() > destination.top()){
                    auxilary.push(destination.top());
                    destination.pop();
                }
                else{ // ( destination.top() > auxilary.top() )
                    destination.push(auxilary.top());
                    auxilary.pop();
                }

            }
        }// End of Step 3

    }
}

}

int main(){

    stack <int> result;
    
    cout<<"---After Moving---"<<endl;

    towersGeneral(result,13);

    while(!result.empty())
    {
    cout<< result.top()<<endl;
    result.pop();
    }
    
    return 0;
}