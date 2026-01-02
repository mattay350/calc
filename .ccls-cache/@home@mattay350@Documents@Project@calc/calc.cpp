#include <iostream>
#include <random>
#include <vector>
#include <chrono> 
using namespace std;

int main (){
  enum Difficulty { Easy, Nomal, Hard };
  bool is_mode=false, loop = true;
  int max,lvalue,rvalue,ope,ans,u_ans,q=0,currect=0,uncurrect=0;
  char c;
  Difficulty mode;
  
  random_device rd ;
  seed_seq s = { rd(), rd(), rd() } ;
  mt19937 e(s) ;
  uniform_int_distribution<int> d(0,200);          
  //select mode
  do{
    cout << "Please select a difficulty level." << endl;
    cout << "{ Easy:e, Nomal:n, Hard:h }"  << endl;  
    cin >> c;
    if (c == 'e') {
      mode = Easy;
      is_mode = true;
      max = 10;
    }
    if (c == 'n') {
      mode = Nomal;
      is_mode = true;
    }
    if (c == 'h') {
      mode = Hard;
      is_mode = true;
    }
  }while(!is_mode);

  auto start = std::chrono::system_clock::now();
  while (loop) {
    
    switch(mode){
    case Easy:
      
      lvalue=d(e);
      rvalue=d(e);
      ope =d (e)%2;
      switch (ope) {
      case 0:
        ans = lvalue + rvalue;
        cout << "Q" << q << " : " << lvalue << "+" << rvalue << "=";
        break;
      case 1:
        ans = lvalue - rvalue;
        cout << "Q" << q << " : " << lvalue << "-" << rvalue << "=";
        break;
      }
      cin >> u_ans;
      cout << "\e[2A" <<flush;
      std::cout << "\033[1A\033[2K\r" << std::flush;
      if (u_ans == ans) {
        cout << "   << currect!!" << endl;
        currect++;
      } else {
        cout << "\033[1A\033[999C"
             << "   << you are idiot!!  ans :"<<ans<< endl;
        uncurrect++;
      }
      q++;
      if (q == max) {

        loop = false;
      }

      break;

    case Nomal:
      break;

    case Hard:
      break;
    }
  }

      auto end = std::chrono::system_clock::now();    
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    //result
    cout <<"///////////////////////////////////////////////////"<<endl;
    cout << endl;
    cout << "Anser currect/uncoorect :"<< currect << "/" << uncurrect << endl;
    cout << "Time :"<< duration/1000 << "s" << endl;    
    cout << endl;    
    cout <<"///////////////////////////////////////////////////"<<endl;
    cin.get();
}
