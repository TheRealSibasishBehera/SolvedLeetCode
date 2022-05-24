class Solution {
    public int[] searchRange(int[] arr, int n) {
        int s = 0;
        int e = arr.length - 1;
        int k=-1,t=-1;
        int a=0;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (n > arr[mid]) {
                s = mid + 1;
            } else if (n < arr[mid]) {
                e = mid - 1;
            } else if (n == arr[mid]) {k=mid;
                e = mid - 1;}}
            s = 0;
            e = arr.length - 1;
            while (s <= e) {
                int mid = s + (e - s) / 2;
                if (n > arr[mid]) {
                    s = mid + 1;
                } else if (n < arr[mid]) {
                    e = mid - 1;
                } else if (n == arr[mid]) {t=mid;
                    s = mid + 1;}}

            return new int[]{k,t};
        
    }
}