#ifndef ADVENT_OF_CODE_PUZZLE_H
#define ADVENT_OF_CODE_PUZZLE_H

#include <iostream>
#include <string>
#include <set>

using namespace std;

class Puzzle {
    const string signal{
        "qfmfhmhjmjggwbbvdvwvlvrrtsrsccwsslvlffjrrtprprjjvmmclmmghhddpvddclctcqtccgbgdbgdgsdgghqhtqtvvptvppwrwprpvrrrhpphththvhhrnnhnlnslnlhnhnhgnhnpnqqsmsgsllprlprrlzzqzffmzztctbtnbtthlttqvqcqmcmpcpbbczzbqbgghcghchhvwvllfrfnnbssfzsszpsplpglpprnpnfnbnhbnbtbzzvbvpbbhjjlzzbtbvbppczppbwppqwwnwlwccglgvgrgmmdwmwrmrppnfnhhhhqthqthqqrhrshhhqbhqqjgjvjllzvzbzhbbpttjsszvzqqtzzmbmddpldpdcdnccrmcrmmpwprplrrqssvddmpdmmwfwwlrljrrdsssmhsspnpffjggqllnzlnlhnnmddfrfpfbbvssjsrrznngcghgchcmhmrrrtzztjzzhchssslsmlmvvpwpqpjqjdddmsdmmtgtmgtglttfbbgrrcprrqffmmjnjttcmczzgbzggthhsttpggrmmgwwnpnqnqvnqvqppmlpmlpmpjpljljmmtpptfppfrppfdpfdppddmdttgzgzzdbzdzhzhnnsqssvmvbbpjjzwwvnwvvzmvzmzpmpttvrvccqddpgdppgmmthmthtggsfsbbvfbvfvhfvhvvpwpddqrqgqhghnnfmfbbwrbrgbgbvgbbdttffrddqbqpqzzmttlhhsqhsqhsqhhlplttpnpsstpthhpfhpfplprrgfrgffjppghgppghgdggjmmcgmccjvvsrvsrrwgrgmrrngrgttvbtbltthrthrttmfffjpfpssncnrngrrltrltlggjgcgllrzzllhwwjwrwgrgsrgrhrphrhhqwqsqmqlmqlmqmqrmrnnwnhwnhwhzwzjwwgbghhsjspszsznzfztfzfpzzlczztctsstctqtfqfqcfqqjrjccttmqqfpfdfnfwnffqbfbblpbpfpcfcwfccblbwwmqwqrrgprpccngnhghpppwmpplcppfrfjjgmmbzbhbcbzzgdgsdsvvqllzlppnfnlnlslsljlppcscqqfjjjwzwppfgfjjsvvsggjbjljpjpzjzrzjrzzfnfpnfpnfpnfnsnggmpggdllpmmrhhdqqppttgqqcsqsjsbjsjrsrqrbqqmbmcbmcbmbfmfvfqqdbdppmrprnrggmjjhnhbhdhbbfcbbcjjdhhwjwmjmssjswscswcwzccbgbqqmqgmmsdsjsbsdbsddvttjpppcqpcqcgqqslqsssczszrzvvrtvvjppswwhnnwlwtwhhwwzfwwpfpddlvvnvnnvlnntjtqjqjzzjttvvbqbhqbhbbbwnwhnwnppdbpdpvddrqdqjjlvlqqdfdhdjhdjdcjcrcjjggfmfvvfllvfvgglzllmhmzmdddfwddqjjqjfqfcfrrstrssptsstllrflfwwgswslwlbwbwjjvhvfvhfhffhsslwsllbnbblccbwwjqwqqdllrdrnrnffcbbqqpnqqdmdndtntvvrjvvsvmvgvnnmjlwgnjcwljgwnrwpqlztwrpmpgqtwlhrcwsrrhqhjhznrtpqfdnzbfqrzwslptdbdcnqvcllpjsfdvmzqwvzbpnmfcfcjnbmhtwhttjgtnczwctpdthhwmzvzrrgsnmbflgmszgsbvghbzgcmcmszgsbfmlmpbdspqlftmqrcjtmvgcrzznlfwjcbmddplsqrfflqnqfsldwhnncczdmfrrrsbjjqsdzrsgbdbwjbslfcqglsqfddhdsrcdrgqfqthgmfjvnfdfgdncfzpvqcpscnpmfgvqbfwszwzgmqvmcrdrwplfshdgqrchmccpqfznbmfvlhdpctlqgjslrwhjfjlmqfblgjrdlnzdtwlpwhnrhrcrpfwqpmjlgrdbgpbljntmbqlblqqqpgrnjtmjqvjpzvsqdpgtchmmwbhtmgcjqdplrtptqcvdjjpqdzsrcjhcwvdcghlwrdhtdfctmqfcjcqhcvvbzgsvlggcrdgqbtznwwmnbgsfrjprqgcmlswftlwpqqqvshdprldrsghmhrqvmqmvglbvzpvtrjbhcvhqmvdtcvsllznqzjmhpnlbhmlzthbwwhhvdtcdfdcdzhnbsrnqqjvzzsvfjhbsdlsbdlqjnlpnhfcjtdppzmphghltztzcdvzwbftbvwhvgmrllqfzrpbltptdtjjqtfwjfmczzgdvclqbsbftgtlhnhrrvbpvdltstdnhqvpvtjhmghptvsfnlspslmfsftzdrwljrgblgmcbmlszmhnlfdtmsrnjqwrfmsnfgpcqgzmlwppffrmbvhnlstfpgzwwmwffrqpdfvrspbczbrclwljgzfhpsrwwpdndfgjwbjtftnjrqvmtmzvjmtlmjhhptmgjvfrlzncmhnmpfcwpjbcpftqfzvmtldqhjpwvzrdnvnwnscgzslvfgjjpcvjshctmmpjbgdwtdjtlmztsbmwrjtmltnlsmwmjnpcgpprnfwcqdldbbqbfmdnvprzqwvntgzdbrsgdpgdjbcblmqpdphmwgvbgwlpblflphvjgjsjfshbjdftcqmsdnrzbgngcvddddjvrndhdcscqqswrnvslfrlvvncqjhzlbhdqhtrlvdsvjsbglhfzfphmzfmzqdvjqdwhjgfdwmzsdmbjzstjddfmfqjhmbdgdbvvhbqgstrzpvhpthhbwljczzrmvgsmbqvzdrmhvvjlmphzjfbmfqvwhtnrlfnfmqnnjvnwjswzshwgljmfjhrwbwgtpdqnqgqdzbssbjfbsgwmfzpfjdrtrnmsdffhnbgnrdlbjzfjrvtjgjgcvvzgllljrcrshczvpfqgnwnjjnhbwgvzwrptrgrdgtczjfzzndsqhqpmtqsvmcncfszsjllzzsjjmwgplpjwlhnhgbhctrttgzqbbcflzqvqgmhgdtlvfpbtncbwsjgnzpmbspcqzzwfplfprqlnbctwwrzpjtpfrmnpvnjrjppqrzjrcmggfmhrstzhmsjllcgjhwrbhcrvdvgmvjqqgmczlmhstmthzphlvrrvqmhjzzfzbhphstflhfjdlwqvzlsszctrdchwjssdfjjfzszlqdtwwthfjdqprpfftgdrpdhhcsdcpjbhdrgzwbgjspmffcmgcjnpmwsqwsvpfwzddlcpvlgpvctrssghndhvdmmmgndcjvhdjwttqphsjpgfbsdczmplfpwpzzjlbhrjptmsshfttnmhzdzmjctbltqjmfnpndqgwjzwdwrgdjdmcbtvjqwjngrtbfrwcttpdvcqtwqndznbchjqcqttrhjpjgwdbwzvwgmdsdfmpdwctvntvnsdmfnznfrsdcllpgpnstrrfrwrfrwnhbclnqhltrcdwqwzzldgbbtzmcvnbzmwcmntqpbscqrpzcjnbgbrzpcrcmdmdfsfgdpmgvwccqjrltrgfvjdgbhjndnmtnjjhzvghscdhnhflwplrqdzrnlnsvrtrdnphgqwjwqcjvtfdfshqdwbsvgrqbdlncjmhdmrlsvdnrhztznczzllsvpqlvwgqjvgvvwgrjcvtjvhrsgbdgvlmmtjbwrnftzphnqslcpggztgsdbjsbdtzwprsbcljpbwjhcrffnvtplcdlgmbtcgbllbdmwhwcllbqstnqqvdbcjrglwbmcfqvlvtpqncbspbphflvvrrsprlhqspfmqrsdtdlftsfzrqwdfffbhccvpfdtlptqzllfsbbrfnhjgwhlfcwmmjgjndcwfhdzvvvrzmwllthwsdmbbsrfrzmqnlnqnjnfpgfvrhsbzhjftmvzrzpqpmlcbnwmbssmvssmmqpvwnsjppdhmnhpntlvqmjnbmtvjnmtbpbzrcfhjfhvztnwrmthbswwthjddjmsdnjmzhhpjdllgscdrgmhfpljfzsmszqsqqgrznddhfmstzdcqpgztgwwqpvrghtmqlgdddlqqwwwtnpldbqtf"
    };
//    const string signal{
//            "zcfzfwzzqfrljwzlrfnpqdbhtmscgvjw"
//    };

private:
    bool distinct(int distinct_chars, int start_index, const string& signal, int& arrival) {
        int n = signal.length();
        for (int i = start_index; i < n; ++i) {
            string marker = signal.substr(i, distinct_chars);
            set<char> marker_set;
            for (auto c: marker) {
                marker_set.insert(c);
            }
            if (marker_set.size() == distinct_chars) {
                arrival = i + distinct_chars;
                return true;
            }
        }
        arrival = -1;
        return false;
    }

public:
    Puzzle(string input) {
        int arrival = 0;
        if (distinct(4, 0, signal, arrival)) {
            cout << "distinct chars = " << arrival << endl;
        }
        int msg_arrival = 0;
        if (distinct(14, 0, signal, msg_arrival)) {
            cout << "distnct msg chars = " << msg_arrival << endl;
        }
    }
};

#endif //ADVENT_OF_CODE_PUZZLE_H
