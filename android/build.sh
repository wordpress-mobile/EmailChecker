#!/bin/sh

./gradlew build

VERSION=0.2
GROUP_ID=org.wordpress

# Push to the local maven repo
mvn install:install-file -Dfile=build/libs/EmailChecker-$VERSION.aar -DgroupId=$GROUP_ID -DartifactId=emailchecker -Dpackaging=aar -Dversion=$VERSION

mvn install:install-file -Dfile=build/libs/EmailChecker-$VERSION-debug.aar -DgroupId=$GROUP_ID -DartifactId=emailchecker-debug -Dpackaging=aar -Dversion=$VERSION
