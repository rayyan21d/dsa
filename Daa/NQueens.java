public class NQueens {


    static int []x;
    // k is the current row
    // i is the current column
    // returns true if a queen can be placed in row k and column i
    static boolean place (int k, int i) {
        for (int j=1; j<k; j++) {
            if(x[j] == i || Math.abs(x[j]-i) == Math.abs(j-k)) {
                return false;
            }
        }
        return true;
    }


    // k is the current row
    // n is the number of queens
    static void nQueens(int k, int n, int[] x) {

        for (int i=1; i<=n; i++) {
            if(place(k, i)) {
                x[k] = i;
                if(k == n) {
                    printSolution(n);
                } else {
                    nQueens(k+1, n, x);
                }
            }
        }
        
    }


    static void printSolution(int n) {
        for (int i=1; i<=n; i++) {
            System.out.print(x[i] + " ");
        }
        System.out.println();
    }


    public static void main(String[] args) {

        int [] boardsizes = {1, 4, 6};
        for (int n: boardsizes) {
            System.out.println("Solutions for " + n + " queens:");

            
            x = new int[n+1];
            nQueens(1, n, x);
            System.out.println();
        } 
    }


}