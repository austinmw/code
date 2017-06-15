#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

typedef string KeyType;

typedef string DataType;


int main(int argc, char const *argv[])
{
  int NumVals=stoi(argv[1]);
  int NumFind=stoi(argv[2]);

  bool testing = (argc > 3) ? true : false;

  map<KeyType, DataType > database;

	vector<KeyType> f(NumFind);
   
  KeyType key;
  DataType data;
  
  for (int ii=0; ii < NumVals; ii++){
    	cin >> key >> data;
      database[key] = data;
    }

    for (int ii=0; ii < NumFind; ii++)
    	cin >> f[ii];

   
    // Find the 3 nearest values in v to each value in f.



  if (testing) {
     for (auto it = database.begin() ; it != database.end(); it++)
        cout << "k: " << it->first << ", d: " << it->second <<endl; 
   }

  for (auto keytofind : f) {

     auto it = database.find(keytofind);   
     auto suc = it;
     auto pre = it;
     pre--; // go previous
     suc++; // go next

     if (it != database.end()){
      // oooops: map<KeyType, DataType >::iterator suc,pre;
      
       //?? auto pre = it-1;
       // if (it != database.begin())
       //    pre = it-1;
       //  else
       //    pre = nullptr;


       if (testing){
        cout << "Found " << keytofind <<endl;
        cout << "predecessor" <<endl;
         if (it != database.begin()) cout << "k: " << pre->first << ", d: " << pre->second <<endl; 
         cout << "value" <<endl;
         cout << "k: " << it->first << ", d: " << it->second <<endl; 
         cout <<"successor" << endl;
         if (suc != database.end()) cout << "k: " << suc->first << ", d: " << suc->second <<endl; 
      }
      else {

        cout << ( (it !=database.begin() )      ? pre->second : "-end-") << " " 
             <<                                    it->second << " " 
             << (  (suc != database.end())      ? suc->second : "-end-") << endl;
      }
     }

  }


	return 0;
}