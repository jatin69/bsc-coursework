#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){

	int code;
	string line; 

	
	ifstream iobs;
	iobs.open("sender.txt");

	// Hash for sender's file
	code=0;
	while(getline(iobs,line)){
		for(int i=0;i<line.length();i++){
			code^=line[i];
		}
		code^='\n';
	}
	int sHash=code;
	
	ifstream oobr;
	oobr.open("receiver.txt");

	// Hash for Receiver's file
	code=0;
	while(getline(oobr,line)){
		for(int i=0;i<line.length();i++){
			code^=line[i];
		}
		code^='\n';
	}
	int rHash=code;

	cout<<"\n ** Hash Check **\n";
	cout<<"\nHash for sender's   file is : "<<sHash;
	cout<<"\nHash for receiver's file is : "<<rHash;

	if(sHash==rHash){
		cout<<"\n\nHash Matched. File is Authentic !!\n\n";
	}
	else{
		cout<<"\n\nHash Does not Match. File has been Tampered !!\n\n";
	}



	return 0;
}