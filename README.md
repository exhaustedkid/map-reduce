# My mapreduce system

# How to use it?
You need to write your scripts ```map(key,  value) -> (key', value')``` and ```reduce()```. Program automatically will sort your data and make writing ```mapreducekakds```

You can launch program as

```./mapreduce -map "path_to_your_map_script" [files where to read from] [file were to write]```

```./mapreduce -reduce "path_to_your_reduce_script" [file where to read from] [file were to write]```

# Example

```./mapreduce -map ./word_count_map in1.txt in2.txt in3.txt out.txt```

```cat output.txt```

car  1

plain  1

car  1

car  1

bus  1

robot  1

bus  1

plane  1

plate  1

```cat in1.txt```: car plain car

```cat in2.txt```: car bus robot

```cat in3.txt```: bus plane plate

```./mapreduce -reduce ./word_count_reduce out.txt dist.txt```

```cat dist.txt```

bus  2

car  3

plain  1

plane  1

plate  1

robot  1

![Example](https://github.com/exhaustedkid/map-reduce/blob/main/example.png)
