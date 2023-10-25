#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

#define f first
#define sec second
#define pb push_back
#define pob pop_back
#define for0(i,n) for(long long i=0;i<n;i++)
#define for1(i,n) for(long long i=1;i<=n;i++)
#define all(v) v.begin(),v.end()
#define lb lower_bound
#define ub upper_bound
#define fix(f,n) setprecision(n)<<f
#define YES {cout<<"YES\n";return;}
#define NO {cout<<"NO\n";return;}

typedef long long ll;
typedef vector<long long> vll;
typedef vector<vll> vvll;
typedef vector<int> vi;
typedef vector<pair<long long,long long>> vpll;
typedef vector<pair<int,int>> vpii;
typedef pair<long long,long long> pll;

const ll inf=1e18;
const ll infi=1e9;


int maxMoves(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    // Initialize a 2D DP array to store the maximum moves from each cell
    vector<vector<int> > dp(m, vector<int>(n, 0));

    // Initialize DP array with 1 for the first column
    for (int i = 0; i < m; i++) {
        dp[i][0] = 1;
    }

    // Iterate through the grid to update the DP array
    for (int col = 1; col < n; col++) {
        for (int row = 0; row < m; row++) {
            for (int dRow : {-1, 0, 1}) {
                int newRow = row + dRow;
                if (newRow >= 0 && newRow < m && grid[newRow][col - 1] < grid[row][col]) {
                    dp[row][col] = max(dp[row][col], dp[newRow][col - 1] + 1);
                }
            }
        }
    }

    // Find the maximum moves in the last column
    int maxMoves = 0;
    for (int i = 0; i < m; i++) {
        maxMoves = max(maxMoves, dp[i][n - 1]);
    }

    return maxMoves;
}

int main() {
    vector<vector<int>> grid1 = {{2, 4, 3, 5}, {5, 4, 9, 3}, {3, 4, 2, 11}, {10, 9, 13, 15}};
    vector<vector<int>> grid2 = {{3, 2, 4}, {2, 1, 9}, {1, 1, 7}};

    cout << maxMoves(grid1) << endl; // Output: 3
    cout << maxMoves(grid2) << endl; // Output: 0

    return 0;
}
