public class Bfs {
    static int visited[];
    static int rear, front;
    static int queue[];


    public static void bfs(int[][] graph, int n, int vertex) {

        visited = new int[n];
        queue = new int[n];
        front = 0;
        rear = -1;
        
        visited[vertex] = 1;
        queue[++rear] = vertex;
        
        while(front<=rear){
            
            vertex = queue[front++];
            System.out.print(vertex+"->");
            
            for(int i=0; i< graph.length; i++){
                if( graph[vertex][i] == 1 && visited[i]==0 ){
                    queue[++rear] = i;
                    visited[i] = 1;
                }
            }
        }

       
        
    }
    public static void main(String[] args) {

        int n = 6;
        int [][] graph = new int[][]{
            {0, 0, 1, 1, 0, 1},
            {0, 0, 1, 0, 1, 0},
            {1, 1, 0, 0, 1, 1},
            {1, 0, 0, 0, 0, 1},
            {0, 1, 1, 0, 0, 0},
            {1, 1, 1, 1, 0, 0}
        };

        bfs(graph, n, 0);


      
    }




}
