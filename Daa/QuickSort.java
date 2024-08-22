public class QuickSort{
    public static void main(String[] args) {
        
        int n = 10;
        int[] arr = new int[n];

        arr = new int[]{100, -9, 48, 47, 16, 35, 24, 53, 02, 100};


        for(int i=0; i<n; i++){
            System.out.print(arr[i] + " ");
        }

        System.out.println();

        
        quickSort(arr,0, n-1);


        System.out.println("After Sorting");
        for(int i=0; i<n; i++){
            System.out.print(arr[i] + " ");
        }

        
    }


    public static void quickSort(int [] arr, int low, int high){

        if (low < high) {
            int p = partition(arr, low, high);
            quickSort(arr, low, p - 1);
            quickSort(arr, p + 1, high);
        }

    }

    public static int partition(int[] arr, int low, int high){

        int p = arr[low];
        int i = low+1;
        int j = high;

        while(i<=j){
            if(arr[i] <= p){
                i++;
            }else if(arr[j] > p){
                j--;
            }else if(i<=j){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        int temp = arr[low];
        arr[low] = arr[j];
        arr[j] = temp;

        return j;

    }
}