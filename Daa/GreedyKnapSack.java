import java.util.Random;


// Greedy approach to solve the fractional knapsack problem
// The greedy approach is to calculate the ratio of profit to weight for each item
// Sort all items by this ratio in descending order
// Take the item with the highest ratio and add it to the knapsack
// Repeat this process until the knapsack is full

// Time complexity: O(n^2 + n) i.e sorting + traversal 
// Space complexity: O(n)

public class GreedyKnapSack{

    public static void main(String[] args) {
       
        Random r = new Random();
        int n = r.nextInt(7) + 3;     // Number of items
        int m = r.nextInt(100) + 5;   // Knapsack capacity

        float profits[] = new float[n];
        float weights[] = new float[n];

        for(int i=0; i<n; i++){
            profits[i] = r.nextInt(200) + 10;
            weights[i] = r.nextInt(30) + 5;
        }

        for (int i = 0; i < n; i++) {
            System.out.println("Item " + (i + 1) + " Profit: " + profits[i] + " Weight: " + weights[i]);
        }

        sort(n, profits, weights);

        float[] ret = knapSack(n, m, weights, profits);

        for(int i=0; i<n; i++){
            System.out.println("Item " + (i + 1) + " Price: " + ret[i]);
        }

    }

    public static void sort(int n, float profits[], float weights[]){

        for(int i = 0; i < n; i++) {
           for(int j=i+1; j<n; j++){


                if(profits[i]/weights[i]< profits[j]/weights[j]){
                    
                    float temp = profits[i];
                    profits[i] = profits[j];
                    profits[j] = temp;

                    temp = weights[i];
                    weights[i] = weights[j];
                    weights[j] = temp;
                }

           }
        }

        for (int i = 0; i < n; i++) {
            System.out.println("Item " + (i + 1) + " Profit: " + profits[i] + " Weight: " + weights[i]);
        }
    
    }


    public static float[] knapSack(int n, int capacity, float weight[], float profits[]) {

        float[] price = new float[n];
    
        
        int totalValue=0;
        for(int i = 0 ; i < n; i++) {

            if(weight[i] <= capacity) {
                
                totalValue += profits[i];
                capacity -= weight[i];
                price[i] = profits[i];

            } else {
                totalValue += (profits[i] * (capacity / weight[i]));
                price[i] = profits[i] * (capacity / weight[i]);
                break;
            }
        }

        System.out.println("Total value: " + totalValue);

        return price;
    }


}