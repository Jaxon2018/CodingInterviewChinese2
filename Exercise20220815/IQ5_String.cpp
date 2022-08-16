// swap s[i] and s[j]
int tmp = s[i];
s[i] = s[j];
s[j] = tmp;

// my solution
class Solution {
public:
    string replaceSpace(string s) {
        // char* start = s;
        // char new_string[18] = {'0'};        
        int count_blank = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == ' ')
            {
                ++count_blank;
            }
        }

        int i = s.size() - 1;
        s.resize(s.size() + count_blank * 2);
        int j = s.size() - 1;
        for(; i >= 0; i--, j--)
        {
            if(s[i] == ' ')
            {
                s[j] = '0';
                s[--j] = '2';
                s[--j] = '%';
            }
            else{
                s[j] = s[i];
            }
        }
        return s;
    }
};

// Carl Answer
class Solution {
public:
    string replaceSpace(string s) {
        int count = 0;
        int sOldSize = s.size();
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == ' ')
            {
                count++;
            }
        }
        s.resize(s.size() + count * 2);
        int sNewSize = s.size();

        for(int i = sNewSize - 1, j = sOldSize - 1; j < i; i--, j--)// j < i
        {
            if(s[j] != ' ')
            {
                s[i] = s[j];
            }else{
                s[i] = '0';
                s[i - 1] = '2';
                s[i - 2] = '%';
                i -= 2;                     // i -= 2;
            }
        }
        return s;
    }
};

//-----------------
void ReplaceBlank(char string[], int length)
{
      if(string == nullptr || length <= 0)
            return;
      
      int originalLength = 0;
      int numberofBlank = 0;

      int i = 0;
      while(string[i] != '\0')  // 遍历字符数组string
      {
            ++originalLength;
            
            if(string[i] == ' ')
            {
                  ++numberofBlank;
            }

            ++i;
      }

      int newLength = originalLength + numberofBlank * 2;
      if(newLength > length)
            return;

      int indexofOriginal = originalLength; // 遍历字符数组string
      int indexofNew = newLength;
      while(indexofOriginal >= 0 && indexofNew > indexofOriginal) // indexofOriginal >= 0
      {
            if(string[indexofOriginal] == ' ')
            {
                  string[indexofNew--] = '0';
                  string[indexofNew--] = '2';
                  string[indexofNew--] = '%';
            }else{
                  string[indexofNew--] = string[indexofOriginal];
            }

            --indexofOriginal;

      }
}