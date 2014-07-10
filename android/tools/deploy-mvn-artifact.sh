#!/bin/sh +v

. tools/deploy-mvn-artifact.conf
PROJECT=.
VERSION=`grep -E 'version' $PROJECT/build.gradle \
		| sed s/version// \
		| grep -Eo "[a-zA-Z0-9.-]+"`
GROUPID=org.wordpress
ARTIFACTID=emailchecker
AARFILE=build/outputs/aar/email-checker-$VERSION-release.aar

# Deploy release build
mvn deploy:deploy-file -Dfile=$AARFILE \
	-Durl=$LOCAL_GH_PAGES -DgroupId=$GROUPID \
	-DartifactId=$ARTIFACTID -Dversion=$VERSION

echo ========================================
echo
echo \"$GROUPID:$ARTIFACTID:$VERSION\" deployed