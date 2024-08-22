public class Dfs {

    static boolean[] visited;
    public static void main(String[] args) {

        int n = 6;
        int [][]graph;

        graph = new int[][] {
            {0, 1, 1, 0, 0, 0},
            {1, 0, 0, 1, 1, 0},
            {1, 0, 0, 0, 0, 1},
            {0, 1, 0, 0, 0, 0},
            {0, 1, 0, 0, 0, 0},
            {0, 0, 1, 0, 0, 0}
        };


        visited = new boolean[n];
        System.out.println("DFS of Graph :");
        
        dfs(graph, 0);
        System.out.println();

    }

    public static void dfs(int[][] graph, int vertex) {
        
        visited[vertex] = true;
        System.out.print(vertex + " -> ");
        for(int i = 0; i < graph.length; i++) {
            if(graph[vertex][i] == 1 && !visited[i]) {
               
                dfs(graph, i);
            }

        }
    }
}
