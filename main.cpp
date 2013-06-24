/*
 * File: RandomWriter.cpp
 * ----------------------
 * Name: Atul Agrawal
 * This file is the starter project for the Random Writer problem.
 * Date:24.07.2013
 */
#include<iterator>
#include <iostream>
#include<fstream>
#include<string>
#include"foreach.h"
#include"map.h"
#include"vector.h"
#include"simpio.h"
#include"random.h"
using namespace std;
void readInput(ifstream &it,int order);
void writeOutput(Map<string,Vector<char> > &freq);

int main() {
  ifstream it;
	string s;
	int a;
	cout<< "Enter the name of TestFile with Extension" << endl;
	s=getLine();
		while(true){
			it.open(s.c_str());
			if(it.fail()){
				it.clear();
				cout << "Sorry.File Not Found.Enter a valid File Name" <<endl;
				s=getLine();
				cout << s << endl;
				}
			else{
				break;
			}
		}
		
		cout <<"Enter a order between 1 to 10(Higher the Order Higher the accuracy)" << endl;
		a=getInteger();
		while(true){
			if(a>=1 && a<=10) {
				cout<<"You are too Lazy :-P Don't worry we will write it for you..Loading!!!";
				break;
			}
			else {
				cout <<"Sorry.Integer must be between 1 to 10.Enter an Integer";
				a=getInteger();
			}
		}
		readInput(it,a);
	
    return (0);
}

void readInput(ifstream &it,int order){
	string seed;
	Vector<char> a;
	Map<string,Vector<char> > frequency;
	
	for(int i=0;i<order;i++){
		seed+=it.get();					//assuming the file size to be greater than order;
	}
	while(!it.fail()){
		
		char temp;
		temp=it.get();
		if(frequency.containsKey(seed))			//doubt
			frequency[seed].add(temp);
		else{
			Vector<char> c;
			c.add(temp);
			frequency.put(seed,c);
		}
		seed=seed.substr(1)+temp;
	}
	writeOutput(frequency);
}


void writeOutput(Map<string,Vector<char> > &frequency){
	ofstream ott;
	string key;
	
	int maxSize=0;
	string maxKey="";
	int tempSize=0;
	
		foreach(string str in frequency){
			if(frequency.containsKey(str)){
				Vector<char> a=frequency[str];
				tempSize=a.size();
				if(tempSize>maxSize){
					maxKey=str;
					maxSize=tempSize;
				}
			}
		}	
	ott.open("output.txt");
	key=maxKey;
	ott << key;
	
	for(int i=0;i<2000;i++){
		if(frequency.containsKey(key)){
			Vector<char> listOfStrings=frequency[key];
			int size=listOfStrings.size();
			char ch=listOfStrings.get(randomInteger(0,size-1));
			ott << ch;
			key=key.substr(1)+ch;
		}
	}
}
