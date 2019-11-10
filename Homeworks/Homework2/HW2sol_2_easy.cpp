#include<iostream>
using namespace std;

int main()
{
    int n, m;
    int a[1024], b[1024];
    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<m; i++) cin >> b[i];

    /// If 2nd sequence has more members than the 1st one, it is impossible for the 2nd to be a subsequence of the 1st
    if(m>n)
    {
        cout << "Not a subsequence!" << endl;
        return 0;
    }

    int ind=0, ind2=0;
    int t[1024];
    for(int i=0; i<n; i++) /// iterating each number in the 1st sequence
    {
        if(b[ind]==a[i]) /// if we find b[ind] element in the 1st sequence (starting from ind=0 to ind=m)
        {
            ind++; /// we have found it and therefore we move to the next one
            if(ind>=m) /// if we have gone trough all elements in b => b is a subsequence of a
            {
                for(++i; i<n; i++)
                {
                    t[ind2++] = a[i]; /// we add all the remaining elements of a to the trash numbers
                }
            }
        }
        else
        {
            t[ind2++] = a[i]; /// if the current element of a isn't b[ind], we move it to the trash numbers
        }
    }

    if(ind != m) /// if ind!=m => we haven't seen all the numbers from b in a
    {
        cout << "Not a subsequence!" << endl;
        return 0;
    }

    /// if we are here, then we have a solution and we just print the trash numbers
    for(int i=0; i<ind2; i++) cout << t[i] << ' ';
    return 0;
}
