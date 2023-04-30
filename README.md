# My mapreduce system

# How to use it?
You need to write your scripts ```map(key,  value) -> (key', value')``` and ```reduce()```. Program automatically will sort your data and make writing ```mapreducekakds```

You can launch program as

```./mapreduce -map "path_to_your_map_script" [files where to read from] [file were to write]```

```./mapreduce -reduce "path_to_your_reduce_script" [file where to read from] [file were to write]```

# Example
```./mapreduce -map ./word_count_map in1.txt in2.txt in3.txt out.txt```
output.txt:
