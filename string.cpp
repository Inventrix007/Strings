// string.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<algorithm>
#include<string>
#include<iostream>
#include<vector>
#include<iterator>
#include<map>
using namespace std;

class Str {
	typedef vector<char>::size_type size_type;

	//constructor for initialization
	Str();

	//funtion that creates string with n c characters
	Str(size_type n , const char c){
		return data(n,c);
	}

	Str(const char* c){
		copy(c, c + strlen(c), back_inserter(data));
	}

	template<class In> Str(In b, In e){
		copy(b, e, back_inserter(data));
	}

private:
	vector<char> data;

};
















bool isurlchar(string s);
vector<string> inputVector();
void printVector(const vector<string>& s);
string::size_type findLongestStr(const vector<string>& p);
void frameString(const vector<string>& p);
vector<string> findURL(const string& s);
string concatAllElements(const vector<string>& s);
string concat(string s);
void vector_to_string(vector<string> v);
void countWords();
vector<string> split(const string& s);
map<string, vector<int>> xref(istream& in, vector<string> find_words(const string& s) = split);
//*************MAIN FUNCTION STARTS HERE******************
int _tmain(int argc, _TCHAR* argv[])
{								
	vector<string> frame;		
								
	countWords();				
	//frame = inputVector();	
	//string final = concatAllElements(frame);
	//vector_to_string(frame);	
	//printVector(frame);		
	//frameString(frame);		
								
	return 0;					
}								
								
map<string, vector<int>> xref(istream& in, vector<string> find_words(const string& s) = split)
{
	map<string, vector<int>> ret;
	string line;
	int linenumber=0;
	while(getline(in, line)){
		++linenumber;

		vector<string> words = split(line);
		for(vector<string>::const_iterator it = words.begin(); it!=words.end(); it++ ){
			ret[*it].push_back(linenumber);

		}

	}
	
	return ret;
}

void countWords(){
	map<string, int> counters;
	string s;
	while(cin>>s){
		++counters[s];
	}
	for(map<string,int>::const_iterator it = counters.begin(); it!= counters.end(); it++){
		cout<<it->first<<"\t---\t"<<it->second<<endl;
	}

}
string concat(string s){
	static string temp;
	temp +=s;
	return temp;
}
void vector_to_string(vector<string> v){
	vector<string> result;

	transform(v.begin(), v.end(), back_inserter(result), concat);
	vector<string>::size_type size = result.size();
	cout<<*(--result.end());
}

//string concatAllElements(const vector<string>& s){
	/*
	string final = "";
	vector<string>::const_iterator it;
	for(it = s.begin(); it!= s.end(); it++){
		final += +" " +*it;
	}
	cout<<final;

	return final;
	*/
	//return string(accumulate(s.begin(), s.end(), string("")));
//}


void frameString(const vector<string>& p){
	const string::size_type maxlen = findLongestStr(p);
	vector<string> ret;
	string border(maxlen+4, '*');

	ret.push_back(border);

	for(vector<string>::size_type i =0; i!=p.size(); i++){
		ret.push_back('*'+ p[i] + string(maxlen - p[i].size(),' ')+ '*');
	}
	ret.push_back(border);

	printVector(ret);
}
string::size_type findLongestStr(const vector<string>& p){
	string::size_type max = 0;
	string::size_type index = 0;
	for(vector<string>::size_type i =0;i!=p.size();i++){
		if(max <= p[i].size()){
			max = p[i].size();
			index = i;
		}
	}


	return max;
}
vector<string> inputVector(){
	vector<string> temp ;
	cout<<"enter strings:";
	string s;
	while(getline(cin,s)){
		temp.push_back(s);
	}
	return temp;
}
void printVector(const vector<string>& s){
	vector<string>::size_type i;
	for(i =0 ; i!= s.size();i++){
		cout<<s[i]<<endl;
	}
}
/*
vector<string> verticalConcatenation(const vector<string>& top, const vector<string>& bottom){
	vector<string> ret;
	ret = top;
	for(vector<string>::const_iterator it = bottom.begin(); it!= bottom.end(); it++){
		ret.push_back(bottom[it]);
	}

	// ret.insert(ret.end(), bottom.begin(), bottom.end()); // alternative method for same result
	return ret;

}
*/
vector<string> horizontalConcatenation(const vector<string>& left, const vector<string>& right){
	vector<string> ret;

	vector<string>::size_type i =0, j =0;
	 string::size_type maxlen = findLongestStr(left);
	
	while(i!=left.size() || j != right.size()){
		string s;
		
		if(i!=left.size()){
			s = left[i++];
		}

		s += string(maxlen - s.size(), ' ');

		if(j!=right.size()){
			s += right[j++];
		}
		ret.push_back(s);
	}

	return ret;
}
bool isurlchar(string s){
	return 1 ;
}
