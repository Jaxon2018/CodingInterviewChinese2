int GetSize(int data[])
{
      return sizeof(data);
}

int _tmain(int argc, _TCHAR* argv[])
{
      int data1[] = {1, 2, 3, 4, 5};
      int size1 = sizeof(data1);

      int* data2 = data1;
      int size2 = sizeof(data2);

      int size3 = GetSize(data1);

      printf("%d, %d, %d", size1, size2, size3);
}

bool duplicate(int numbers[], int length, int* duplication)
{
      if(numbers == nullptr || length <= 0)
      {
            return false;
      }
      
      for(int i = 0; i < length; ++i)
      {
            if(numbers[i] < 0 || numbers[i] >= length)
            {
                  return false;
            }
      }

      for(int i = 0; i < length; ++i)
      {
            while(numbers[i] != i)
            {
                  if(numbers[i] == numbers[numbers[i]])
                  {
                        *duplication = numbers[i];
                        return true;
                  }

                  //swap numbers[i] and numbers[numbers[i]]
                  int temp = numbers[i];
                  numbers[i] = numbers[numbers[i]];
                  numbers[numbers[i]] = temp;
            }
      }

      return false;
      
}

// my own answer
bool duplicate2(int numbers[], int length, int* duplication)
{
      if(numbers == nullptr || length <= 0)
      {
            return false;
      }
      
      for(int i = 0; i < length; ++i)
      {
            if(numbers[i] < 1 || numbers[i] >= length)
            {
                  return false;
            }
      }

      // int num_record = 
      int record[length - 1] = {0};

      for(int i = 0; i < length; ++i)
      {
            record[numbers[i]-1]++;
      }

      for(int i = 0; i < length - 1; ++i)
      {
            if(record[i] >= 1)
            {
                  *duplication = i + 1;
                  return true;
            }
      }

      return false;

}

// IQ3-2
// how many numbers of numbers in the range frome start to end 
int countRange(const int* numbers, int length, int start, int end)
{
      if(numbers == nullptr)
            return 0;
      int count = 0;
      for(int i = 0; i < length; ++i)
      {
            if(numbers[i] >= start && numbers[i] <= end)
            {
                  ++count;
            }
      }
      return count;
}

int getDuplication(const int* numbers, int length)
{
      if(numbers == nullptr || length <= 0)
      {
            return -1;
      }

      int start = 1;
      int end = length - 1;   // 定义target在左闭右闭的[left, right]闭区间
      while(end >= start)     // 当start == end时，区间[left, right]依然有效，所以使用>=
      {
            int middle = ((end - start) >> 1) + start; // 防止溢出，等同于(start + end)/2
            int count = countRange(numbers, length, start, middle); //这里是闭区间[start, middle]

            if(end == start)
            {
                  if(count > 1)
                  {
                        return start;
                  }
                  else{
                        break;
                  }
            }

            if(count > (middle - start + 1))
            {
                  end = middle; // target在左区间[start, middle],包含了target == middle的情况
            }
            else{
                  start = middle + 1;// target在右区间[middle + 1，end]
            }         
      }

      return -1;
}

//------------------------------------------
// Array 二分查找
class Solution{
public:
      int search(vector<int>& nums, int target)
      {
            int left = 0;
            int right = nums.size() - 1;

            while(left <= right)
            {
                  int middle = left + ((right - left)/2);
                  if(nums[middle] > target)// left, middle - 1
                  {
                        right = middle - 1;
                  }
                  else if(nums[middle] < target)// middle + 1, right
                  {
                        left = middle + 1;
                  }
                  else{
                        return middle;
                  }
            }

            return -1;
      }
}
