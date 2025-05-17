class MapSum {
    Map<String, Integer> mpp ;
    public MapSum() {
        mpp  =new HashMap<>();
    }
    
    public void insert(String key, int val) {
       mpp.put(key, val); 
    }
    
    public int sum(String prefix) {
        Set<String> st  = mpp.keySet();
        int cnt =0 ;
        for(String s :  st){
            if(s.startsWith(prefix)){
                cnt += mpp.get(s);
            }
        }
        return cnt;
    }
}

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */