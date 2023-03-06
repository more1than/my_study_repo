```
FROM centos
MAINTAINET kuangshen<24736743@qq.com>

COPY readme.txt /usr/local/readme.txt

ADD jdl-8u11-linux-x64.tar.gz /ust/local/
ADD apache-tomcat-9.0.22.tar.gz /usr/local/

RUN yum -y install vim

ENV MYPATH /usr/local
WORKDIR $MYPATH

ENV JAVA_HOME /usr/local/jdk1.8.0_11
ENV CLASSPATH $JAVA_HOME/LIB/DT/JAR:$JAVA_HOME/lib/tools.jar
ENV CATALINA_HOME /usr/local/apache-tomcat-9.0.22
ENV CATALINA_BASH /usr/local/apache-tomcat-9.0.22
ENV PATH $PATH:$JAVA_HOME/bin:$CATALINA_HOME/lib:$CATALINA_HOME/bin
```



发布镜像到docker hub中

```bash
docker push author/myimages:v1.0
```

