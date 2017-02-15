# Hidden Markov Model for Java (HMMTK4j)

HMMTK4J is a set of Java classes to do various computation on Hidden Markov Models in Java.
To achieve good performance in computation, a JNI implementation using [ALTERnatives](https://gitlab.projectsforge.org/hmm/alternatives) is used.
Currently it only supports GNU/Linux and MS Windows both in 32bits/64bits version.

Copyright [Sébastien Aupetit](mailto:sebtic@projectsforge.org?subject=HMMTK4j)

# Maven repository

Current artifacts are available through a simple repository. To use the artifacts in a Maven project, you need to add the following to your pom.xml :
```xml
<repositories>
  <repository>
   <id>projectsforge-repository</id>
   <name>Projecsforge.org Public Maven repository</name>
   <url>https://static.projectsforge.org/maven/</url>
   <snapshots>
    <updatePolicy>always</updatePolicy>
   </snapshots>
  </repository>
 </repositories>
```

# Warning

This code is no more actively maintained and is provided AS-IS.