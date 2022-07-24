# Unformatted Input/Output
1. put() : to write single character to Output
2. get(c) : reads single character or string
3. get() : eg: cin.get(str1, MAX, '$') OR cin.get(str1,MAX)
4. getline() : takes multiline input string eg: cin.getline(str1,MAX,'$') or cin.getline(str2,MAX)
5. write() : eg: cout.write(str,strlen(str))
6. read() : cin.read(str,9)
7. ignore() : cin.ignore() ( reads input but doesn't save it )


# Formatted Input/Output
1. width() : cout.width() ( right alignment )
2. fill()
    ```cpp
    eg: int x =456;
    cout.width(6);
    cout.fill('#');
    cout<< x << endl; // ###456
    ```
3. precision() : 
    ```c++
    float x= 5.5005, y=66.769; 
    cout.precision(3);
    cout<<x<<endl;  // 5.5
    cout<<y<<endl; // 66.8
    ```
4. setf() : 
```
+-------------------+---------------------+
|    Flag           |    Bit filed value  |   
+-------------------+---------------------+
| ios::left         |   ios::adjustfield  |
| ios::right        |   ios::adjustfield  |
| ios::interval     |   ios::adjustfield  |
+-------------------+---------------------+
| ios::dec          |   ios::basefield    |
| ios::oct          |   ios::basefield    |
| ios::hex          |   ios::basefield    |
+-------------------+---------------------+
| ios::scientific   |   ios::floatfield   |
| ios::fixed        |   ios::floatfield   |
+-------------------+---------------------+
```

eg:
```c++
int x = 456; 
cout.setf(ios::left, ios::adjustified);
cout.width(6);
cout.fill('#');
cout<< x << endl; // 456###
```
