class Solution {
    public int[] arrayRankTransform(int[] arr) {
        Map<Integer, List<Integer>> mp = new TreeMap<>();
        int[] ans = new int[arr.length];
        for(int i=0; i<arr.length; i++){
            if(!mp.containsKey(arr[i])){
                mp.put(arr[i], new ArrayList<>());
            }
            mp.get(arr[i]).add(i);
        }
        int j=1;
        for(Integer key: mp.keySet()){
            for(Integer idx: mp.get(key)){
                ans[idx] = j;
            }
            j++;
        }
        return ans;
    }
}