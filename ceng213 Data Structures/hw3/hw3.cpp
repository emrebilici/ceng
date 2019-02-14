#include "hw3.h"


AccessControl::AccessControl(int table1Size, int table2Size){
    
//    activeUsers = new vector<std::string>;
//    regUsers = new std::vector<std::pair<std::string,std::string>>;
    
    activeUsers.resize(table2Size);
    regUsers.resize(table1Size);

    this->table1Size = table1Size;
    this->table2Size = table2Size;
    current2 = 0;
    current1 = 0;

    for(int i=0; i < table2Size; i++){
        activeUsers[i] = EMPTY;
    }
    
    for(int i=0; i < table1Size; i++){
     //   regUsers[i].second = EMPTY;
      //  regUsers[i].first = EMPTY;
        regUsers[i] = std::make_pair(EMPTY,EMPTY);

    }

}

AccessControl::~AccessControl(){

//    activeUsers.shrink_to_fit();
//    regUsers.clear();
    std::vector<std::pair < std::string,std::string > >().swap(regUsers);
    std::vector<std::string >().swap(activeUsers);
}


void AccessControl::expandTable1(){
    int tempSize = table1Size;
    current1 = 0;
    table1Size = nextPrime(2 * table1Size);
    std::vector< std::pair <std::string, std::string> > temp = regUsers;
    regUsers.clear();
    regUsers.resize(table1Size);
    
    for(int i = 0; i < table1Size; ++i){
        regUsers[i] = std::make_pair(EMPTY,EMPTY);
        //regUsers.push_back( std::make_pair(EMPTY,EMPTY));
    }
    for(int i = 0; i < tempSize; ++i){
        if(temp[i].first != EMPTY && temp[i].first != DELETED){
            //std::cout<<"expand içi =" << table2Size <<std::endl;
            
            //addUser(temp[i].first, temp[i].second);
            // int hashindex = hashFunction(temp[i].first, table2Size, 0);
            // regUsers[hashindex]=std::make_pair(temp[i].first,temp[i].second);
            for(int j = 0 ; j < table1Size; j++ ){
                int hashindex = hashFunction(temp[i].first, table1Size, j);
                if(regUsers[hashindex].first==EMPTY){
                    regUsers[hashindex]=std::make_pair(temp[i].first,temp[i].second);
                    std::cout<< "---> expand  hashindex -> " << hashindex << " --- " << regUsers[hashindex].second << " <-expand ----  "<<std::endl;
                    break;
                }


        
             }

             current1++; 
        }
       // std::cout << temp[i].first;

    }
    temp.clear();
}

int AccessControl::addUser(std::string username, std::string pass){


    for(int i = 0 ; i < table1Size; i++ ){
        int hashindex = hashFunction(username, table1Size, i);
     //   std::cout<< "hashindex = " <<hashindex <<std::endl;
        if(regUsers[hashindex].first==EMPTY){
            regUsers[hashindex]=std::make_pair(username,pass);

            current1++;
      //        std::cout << "current2 = " <<current2 <<" \n";
       //       std::cout << "table2size = " <<table2Size <<" \n";
            if(((current1 ) / (double)table1Size) > MAX_LOAD_FACTOR )
            { 
                //std::cout<<"expande giriyo =" << table2Size <<std::endl;
                expandTable1();
        //        std::cout<<"expande girdi =" << table2Size <<std::endl;
            }  
            return 1;
            break;
        }
        else if(regUsers[hashindex].first == username){
            break;
        }

        
    }
    return 0;

    
  
}

float AccessControl::printPasswords(){
    for (int i = 0 ; i< table1Size; i++) 
        std::cout << regUsers[i].first << " " << regUsers[i].second << std::endl; 
       std::cout<< current1;
    return current1 / table1Size;
}

int AccessControl::nextPrime(int number)
{
    int next = number+1;
    while (!isPrime(next))
    {
        next++;
    }
    return next;

}

bool AccessControl::isPrime(int number)
{
    for (int i = 2; i <= number/2; i++)
    {
        if (number % i == 0)     
            return false;
    }

    return true;
}

void AccessControl::expandTable2(){
    int tempSize = table2Size;
    current2 = 0;
    table2Size = nextPrime(2 * table2Size);
    std::vector< std::string > temp = activeUsers;
    activeUsers.clear();
    activeUsers.resize(table2Size);
    
    for(int i = 0; i < table2Size; ++i){
        activeUsers[i] = EMPTY;
    }
    for(int i = 0; i < tempSize; ++i){
        if(temp[i] != EMPTY && temp[i] != DELETED){

            for(int j = 0 ; j < table2Size; j++ ){
                int hashindex = hashFunction(temp[i], table2Size, j);
                if(activeUsers[hashindex] == EMPTY){
                    activeUsers[hashindex] = temp[i];
                    break;
                }
             }

             current2++;
        }
    }
    temp.clear();
}


int AccessControl::login(std::string username, std::string pass){
    if(!isValid(username,pass)){
        return 0;
    }
    
    for(int i = 0 ; i < table2Size; i++ ){
        int hashindex = hashFunction(username, table2Size, i);

        if(activeUsers[hashindex]==EMPTY || activeUsers[hashindex]==DELETED){
            activeUsers[hashindex] = username;
            current2++;
            if(((current2 ) / (double)table2Size) > MAX_LOAD_FACTOR )
            { 

                expandTable2();
            }  
            return 1;
            break;
        }
        else if(activeUsers[hashindex] == username){
            return 0;
        }
    }
}

float AccessControl::printActiveUsers(){
    for (int i = 0 ; i< table2Size; i++) 
        std::cout << activeUsers[i] << std::endl; 
    //  std::cout<< current2;
    return current2 / table2Size;
}

bool AccessControl::isValid(std::string username, std::string pass){
    int i = 0;
    int count = 0;
    while(i < table1Size){
        int hashindex = hashFunction(username,table1Size, i);
        if(regUsers[hashindex].first==username){
            
            count++;
            i++;
            std::cout << " username ve kac tane var --> " << username << count <<std::endl;
        }       
        i++;
    }

    i = 0;
    int count1=0;
    while(i < table1Size){
        int hashindex = hashFunction(username,table1Size, i);
        if(regUsers[hashindex].second==pass){
            count1++;
            if(count==count1){
                return true;
            }
        }
        i++;
    }
    return false;

}

int AccessControl::logout(std::string username){
    if(!isLogin(username)){
        return 0;
    }
    for(int i = 0 ; i < table2Size; i++){
        int hashindex = hashFunction(username, table2Size, i);
        if(activeUsers[hashindex]==username){
            activeUsers[hashindex]=DELETED;
            current2--;
            return 1;
        }

    }
}

bool AccessControl::isLogin(std::string username){
    int i = 0;

    while(i < table2Size){
        int hashindex = hashFunction(username,table2Size, i);
        if(activeUsers[hashindex]==username){
            return true;
        }       
        i++;
    }

    return false;

}

int AccessControl::addUsers(std::string filePath){
    std::ifstream file;
    file.open(filePath.c_str());
   
    if (!file.good()){
       return 0;
    }
    std::string username, pass;
    while(getline(file, username ,' ')){

        getline(file, pass);
        addUser(username,pass);
        
   }
        return current1;
}


int AccessControl::changePass(std::string username, std::string oldpass, std::string newpass){


    //isvalidi düzelttikten sonra i leri kıyaslayarak ilerle expandte. sarahı buldun diyelim.
    // hashfunction ile gez. i si en küçük olan en eskidir.
    // belki bu durumda ifin icini eski haline getirmek gerekebilirsin
    // en iyisi ifin icine tekrar atmak current sayıları karısiyo yoksa

     
    if(!isValid(username,oldpass)){
        return 0;
    }
    for(int i = 0 ; i < table1Size; i++ ){
        //int hashindex = hashFunction(username, table1Size, i);

            current1++;

            if(((current1 ) / (double)table1Size) > MAX_LOAD_FACTOR )
            { 
                expandTable1();
            }  

        int hashindex = hashFunction(username, table1Size, i);
            //ifin icindeydi
        current1--;
        if(regUsers[hashindex].first==EMPTY){
            

            current1++;
            regUsers[hashindex]=std::make_pair(username, newpass);
            return 1;
            break;
        }


        
    }
    return 0;
}


void AccessControl::expandTableforChange(){
    int tempSize = table1Size;
    current1 = 0;
    table1Size = nextPrime(2 * table1Size);
    std::vector< std::pair <std::string, std::string> > temp = regUsers;
    regUsers.clear();
    regUsers.resize(table1Size);
    
    for(int i = 0; i < table1Size; ++i){
        regUsers[i] = std::make_pair(EMPTY,EMPTY);

    }
    for(int i = 0; i < tempSize; ++i){
        if(temp[i].first != EMPTY && temp[i].first != DELETED){

     //       for(int j = 0 ; j < table1Size; j++ ){		// for new table. if collision occurs, hashindex change.
       //         int hashindex = hashFunction(temp[i].first, table1Size, j);

                //std::vector < std::string > old;
                for(int k = 0 ; k < tempSize; k++){		// for old table. if given temp[i] has other pass, find others with special hashindex.
        			int hashforsorted = hashFunction(temp[i].first, tempSize, k );
        			if(temp[i].first == temp[hashforsorted].first ){	//if temp[i] is still in the old table, add to new table according to its k value.
        				//old.push_back(temp[hashforsorted].second);
        				for(int j = 0;  j < table1Size; j++ ){		// for new table. if collision occurs, hashindex change.
        					int hashindex = hashFunction(temp[i].first, table1Size, j);
        					if(regUsers[hashindex].first == EMPTY){
        						regUsers[hashindex] = std::make_pair(temp[hashforsorted].first, temp[hashforsorted].second);
        						break;
        					}
        					
        				}
        			}

        		}
    /*            //buradaki j nin en kucugunu al yerlestir sonra buyut.
                if(regUsers[hashindex].first==EMPTY){
                    regUsers[hashindex]=std::make_pair(temp[i].first,temp[i].second);
                    std::cout<< "---> expand  hashindex -> " << hashindex << " --- " << regUsers[hashindex].second << " <-expand ----  "<<std::endl;
                    break;			//after adding to new table, break the hashindex loop for the new table.		
                }
*/


              /*  else if(regUsers[hashindex].first==temp[i].first){ }  */
        
      //       }

             current1++;
 
        }
       // std::cout << temp[i].first;

    }
    temp.clear();
}
