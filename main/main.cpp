#include <iostream>
#include <vector>
#include <fstream>

using namespace std;



double calculateSimilarity(string a, string b) {
   
    int dist[a.size()][b.size()];

    memset(dist, 0, sizeof dist);

    int n = a.size();
    int m = b.size();

    
    for (int i=1; i<n; i++)
        dist[i][0] = i;


    for (int j=1; j<m; j++)
        dist[0][j] = j;


    for (int j=1; j<m; j++) {
        for (int i=1; i<n; i++) {

            int del = dist[i-1][j] + 1;
            int ins = dist[i][j-1] + 1;
            int subs = dist[i-1][j-1];
            int mn;

            if (a[i] != b[j])
                subs++;

            
            mn = min(del, min(ins, subs));
            dist[i][j] = mn;
        }
    }
  
    return (double)(max(n,m) - dist[n-1][m-1]) / max(n,m);
}

string line, maindir, mainStr, curSentence;
string dir[100];
vector<string> mainSentences;
int n;

int main() {
    
    cout << "Enter the number of files that you want to check: ";
    cin >> n;
    for (int i=0; i<n; i++) {
        cout << "Enter the directory of " << (i+1) <<". file: ";
        cin >> dir[i];
    }
    
    cout << "Enter the directory of the main file: ";
    cin >> maindir;

    
    ifstream mainF(maindir);
    while (getline(mainF, line))
        mainStr += line;

    mainF.close();

    for (int i=0; i<mainStr.size(); i++) {
        if (mainStr[i] == '.' or mainStr[i] == '?') {
            mainSentences.push_back(curSentence);
            curSentence = "";
        } else {
            curSentence += mainStr[i];
        }
    }

    for (int i=0; i<n; i++) {

        ifstream curF(dir[i]);
        string curStr="";
        while(getline(curF, line))
            curStr += line;

        curF.close();

        cout << (i+1) << ") Similarity Rate: " << calculateSimilarity(mainStr, curStr) << endl << endl;


        vector<pair<double, pair<string, string> > >comparisons;

        for (int j=0; j<curStr.size(); j++) {

            if (curStr[j] == '.' or curStr[j] == '?') {

                for (int k=0; k<mainSentences.size(); k++) {
                    comparisons.push_back(make_pair(calculateSimilarity(mainSentences[k], curSentence), make_pair(mainSentences[k], curSentence ) ));
                }

                curSentence = "";
            } else {
                curSentence += curStr[j];
            }
        }
        sort(comparisons.begin(), comparisons.end());
        reverse(comparisons.begin(), comparisons.end());

        for (int j=0; j<min((int)comparisons.size(),5); j++) {
            cout << "The most " << (j+1) << ". similar sentence: " <<  comparisons[j].second.first << " | " << comparisons[j].second.second << endl << endl;
        }

    }
}




