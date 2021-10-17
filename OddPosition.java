public class OddPosition {
    public static void main(String[] args){
    int arr[] = new int[] {12,43,5,6,64,78,22,10};
    System.out.println("Elements present on odd position : ");
    for (int i=0;i<arr.length;i=i+2){
        System.out.println(arr[i]);
    }
}
}
