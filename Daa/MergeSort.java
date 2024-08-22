

public class MergeSort{
    

  

    public static void main(String[] args) {
        
        int n = 10;
        int[] arr = new int[n];

        arr = new int[]{100, -9, 48, 47, 16, 35, 24, 53, 02, 100};


        for(int i=0; i<n; i++){
            System.out.print(arr[i] + " ");
        }

        System.out.println();

        
        mergeSort(arr,0, n-1);


        System.out.println("After Sorting");
        for(int i=0; i<n; i++){
            System.out.print(arr[i] + " ");
        }

        
    }
  public static void mergeSort(int[] arr ,int l, int h){
        
        if(l<h){
            
            int mid = (l+h)/2;
            mergeSort(arr, l, mid);
            mergeSort(arr, mid+1, h);
            merge(arr, l, mid, h);
        }

    }

    public static void merge(int[] arr, int l, int mid, int h  ){
    
        int[] temp = new int[h - l + 1];
        int i = l, j = mid + 1, k = 0;

        while (i <= mid && j <= h) {
            if (arr[i] <= arr[j]) {
                temp[k] = arr[i];
                i++;
            } else {
                temp[k] = arr[j];
                j++;
            }
            k++;
        }

        // Copy remaining elements of left half, if any
        while (i <= mid) {
            temp[k] = arr[i];
            i++;
            k++;
        }

        // Copy remaining elements of right half, if any
        while (j <= h) {
            temp[k] = arr[j];
            j++;
            k++;
        }

        // Copy the merged elements back into the original array
        for (i = l; i <= h; i++) {
            arr[i] = temp[i - l];
        }

    }


}