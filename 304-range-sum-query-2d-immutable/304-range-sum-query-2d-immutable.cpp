class NumMatrix {
public:
    vector<vector<int>> cur, row;
    int n, m;
    
    NumMatrix(vector<vector<int>>& matrix) {
        
        n = matrix.size() , m = matrix[0].size();
        
        for( int i = 0 ; i < n ; ++i ){
            
            vector<int> a,b;
            int sum = 0;
            for( int j = 0 ; j < m ; ++j ){
                sum += matrix[i][j];
                b.push_back(sum);
                a.push_back(matrix[i][j]);
            }
            cur.push_back(a);
            row.push_back(b);
            
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        int sum = 0;
        for( int i = row1 ; i <= row2 ; ++i ){
            
            sum += (row[i][col2] - row[i][col1] + cur[i][col1]);
            
        }
        
        return sum;
        
    }
    
};