class Solution {
    public int lengthOfLastWord(String s) {
        String trim_string = s.trim();
        int count = 0;
        for(int i = trim_string.length()-1; i >= 0; i--){
            if(trim_string.charAt(i) == ' '){
                break;
            }
            count++;
        }
        return count;
    }
}