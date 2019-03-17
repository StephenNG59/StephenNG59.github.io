---
layout: post
# layout: default
title:  "Hello Jekyll!"
date:   2019-03-16 20:40:51 +0800
categories: jekyll update
---

# Hi there!
Installation和setup是按照[Jekyll Quickstart][jekyll-quickstart]来进行的

同时参考了[Jekyll Tutorial in Youtube][jekyll-youtube]，这是个全面手把手介绍Jekyll用法的视频合集，个人认为十分出色


# Something to pay attention:
1. 启用jekyll serve时，对_config.yml的修改不会被自动同步，直到下一次执行。

2. 在_config.yml中，baseurl: "/NG_Blog"，url: "https://stephenng59.github.io"。否则在github pages上不能正常显示主题和posts。

To add new posts, simply add a file in the `_posts` directory that follows the convention `YYYY-MM-DD-name-of-post.ext` and includes the necessary front matter. Take a look at the source for this post to get an idea about how it works.

Jekyll also offers powerful support for code snippets:

{% highlight ruby %}
def print_hi(name)
  puts "Hi, #{name}"
end
print_hi('Tom')
#=> prints 'Hi, Tom' to STDOUT.
{% endhighlight %}

Check out the [Jekyll docs][jekyll-docs] for more info on how to get the most out of Jekyll. File all bugs/feature requests at [Jekyll’s GitHub repo][jekyll-gh]. If you have questions, you can ask them on [Jekyll Talk][jekyll-talk].


[jekyll-quickstart]: https://jekyllrb.com/docs/
[jekyll-youtube]: https://www.youtube.com/watch?v=T1itpPvFWHI&list=PLLAZ4kZ9dFpOPV5C5Ay0pHaa0RJFhcmcB
[jekyll-docs]: https://jekyllrb.com/docs/home
[jekyll-gh]:   https://github.com/jekyll/jekyll
[jekyll-talk]: https://talk.jekyllrb.com/
