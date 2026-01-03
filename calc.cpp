#include <iostream>
#include <random>
#include <vector>
#include <chrono> 
using namespace std;

int main (){
  enum Difficulty { Easy, Nomal, Hard };
  bool is_mode=false, loop = true;
  int max,lvalue,rvalue,ope,ans,u_ans,q=1,currect=0,uncurrect=0,d_max,d_min;
  char c;
  Difficulty mode;
  
  random_device rd ;
  seed_seq s = { rd(), rd(), rd() } ;
  mt19937 e(s) ;

  //select mode
  do{
    cout << "Please select a difficulty level." << endl;
    cout << "{ Easy:e, Nomal:n, Hard:h }  :";
    cin >> c;
    if (c == 'e') {
      mode = Easy;
      is_mode = true;
      max = 10;
      d_min =0;
      d_max =300;
    }
    if (c == 'n') {
      mode = Nomal;
      is_mode = true;
      max = 20;
      d_min =0;
      d_max =300;
    }
    if (c == 'h') {
      mode = Hard;
      is_mode = true;
      max = 30;
      d_min =0;
      d_max =300;
    }
  }while(!is_mode);

  uniform_int_distribution<int> d(d_min,d_max);              
  auto start = std::chrono::system_clock::now();
  while (loop) {
    
    lvalue=d(e);
    rvalue=d(e);
    ope =d (e)%2;    

    switch(mode){
    case Easy:      
      switch (ope) {
      case 0: //+
        ans = lvalue + rvalue;
        cout << "Q" << q << " : " << lvalue << "+" << rvalue << "=";
        break;
      case 1: //-
        ans = lvalue - rvalue;
        cout << "Q" << q << " : " << lvalue << "-" << rvalue << "=";
        break;
      }
      cin >> u_ans;
      std::cout << "\033[1A" << std::flush;
      std::cout << "\033[20C" << std::flush;
      if (u_ans == ans) {
        cout << "   << currect!!" << endl;
        currect++;
      } else {
        cout << "   << you are idiot!!  ans :" << ans << endl;
        cout << "\a" << flush;
        uncurrect++;
      }
      break;

    case Nomal:
      break;

    case Hard:
      break;
    }
    if (q == max) {
      loop = false;
    }
    q++;
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
