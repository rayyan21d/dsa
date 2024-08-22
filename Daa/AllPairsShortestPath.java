public class AllPairsShortestPath {

    public static void shortestPath(int [][]graph, int [][]dist, int n){

        // Copy into distance matrix

        for(int i=0; i<n;i++){
            for(int j=0; j<n; j++){
                dist[i][j] = graph[i][j];
            }
        }
        System.out.println("Original Matrix");
        printMatrix(dist);
        
        // Main logic
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){

                    dist[i][j] = Math.min(dist[i][j], dist[i][k]+ dist[k][j]);

                }
            }
        }

        printMatrix(dist);


    }

    public static void printMatrix(int[][]matrix){

        int n = matrix.length;
        for(int i=0; i<n;i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 999999){
                    System.out.print("INF" + " ");
                }else{
                    System.out.print(matrix[i][j] + " ");
                }
                
            }
            System.out.println();
        }

        System.err.println();
    }


    public static void main(String[] args) {
        
        int INF = 999999;
        int[][] graph = {
            {0, 3, INF, 7},
            {8, 0, 2, INF},
            {5, INF, 0, 1},
            {2, INF,INF,0}
        };

        int n  = graph.length;
        int[][] dist = new int[n][n];

        shortestPath(graph, dist, n);



    }
    
}
