
int isShuffle(string s) {
	vector<int> freq(26,0);

	for(char c : s) freq[c-'a']++;

	int oddOcc = 0;
	
	for(int i : freq) if(i%2) oddOcc++;

	return oddOcc <= 1;
}
void solve() {
	string s; cin>>s;
	int swaps = 0;
	if(isShuffle(s)) {
		int i=0;
		int j=s.size()-1;
		while(i < j) {
			if(s[i] != s[j]) {
				int k = j;
				while(k > i and s[i] != s[k]) k--;
				if(k == i) { //no mismatch character.
					swap(s[i],s[i+1]);
					swaps++;
				} else {
					while(k < j) {
						swaps++;
						swap(s[k],s[k+1]);
						k++;
					}
					i++; j--;
				}
			}else {
				i++; j--;
			}
		}
		cout<<swaps;
	}else {
		cout<<"-1\n";
	}

}

void file_i_o() {
	#ifndef ONLINE_JUDGE  
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
int main() {
	clock_t begin = clock();
	file_i_o();
	FIO;
	int t=1;
	while(t--) {
		solve();
	}
	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif
}
