#!/bin/sh

./gradlew clean
./gradlew assemble

VERSION=0.3
GROUP_ID=org.wordpress

# Push to the local maven repo
mvn install:install-file -Dfile=build/libs/email-checker-$VERSION-release.aar \
 -DgroupId=$GROUP_ID -DartifactId=emailchecker -Dpackaging=aar \
 -Dversion=$VERSION

mvn install:install-file -Dfile=build/libs/email-checker-$VERSION-debug.aar \
 -DgroupId=$GROUP_ID -DartifactId=emailchecker-debug -Dpackaging=aar \
 -Dversion=$VERSION
