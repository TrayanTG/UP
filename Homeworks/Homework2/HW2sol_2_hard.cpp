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

    int ind, ind2;
    int t[1024];
    bool f = false;

    for(int i=0; i<n; i++) /// starting with a new beginning each time
    {
        if(f) break;
        ind = ind2 = 0;
        for(int j=i; j<n+i; j++) /// checking the rotation i, i+1, i+2, ..., n-2, n-1, 0, 1, 2, ..., i-2, i-1
        {
            int k=j%n; /// the elements are in circle so if we go to the n-th member, it means we are on the 0th member
            if(b[ind]==a[k]) /// if we find b[ind] element in the 1st sequence (starting from ind=0 to ind=m)
            {
                ind++; /// we have found it and therefore we move to the next one
                if(ind>=m) /// if we have gone trough all elements in b => b is a subsequence of a
                {
                    f = true;
                    for(++j; j<n+i; j++)
                    {
                        k=j%n;
                        t[ind2++] = a[k]; /// we add all the remaining elements of a to the trash numbers
                    }
                }
            }
            else
            {
                t[ind2++] = a[k]; /// if the current element of a isn't b[ind], we move it to the trash numbers
            }
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
