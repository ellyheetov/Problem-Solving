public class Programmers_42577_전화번호_목록 {

    public boolean solution(String[] phoneBook) {
        for (int i = 0; i < phoneBook.length; i++) {
            for (int j = i + 1; j < phoneBook.length; j++) {
                if (phoneBook[j].startsWith(phoneBook[i])) return false;
                if (phoneBook[i].startsWith(phoneBook[j])) return false;
            }
        }
        return true;
    }
}
