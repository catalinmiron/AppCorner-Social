AppCorner Server
============

AppCorner require facebook login, so replace or add code in your deployd to allow fblogin, you find the code in 

`deployd/lib/resources/user-collection.js`

AppCorner require to enable count for entities, so replace or add code in your deployd to allow count, you find the code in 

`deployd/lib/resources/collection/index.js`

Copy all modules from appcorner folder in a new app created with deployd.

Start deployd.

Add one record in SYNC resource from dashboard for example:

`defaultLocale: us`

`numAppsPicker: 100`


Add one record in COUNTRY resource from dashboard for example:

`country: us`


To run AppCorner for iOS on localhost uncomment in Prefix.pch
```objc
//#define SERVER_URL TEST_LOCAL_URL
//#define SERVER_URI TEST_LOCAL_URI
//#define SERVER_PORT TEST_LOCAL_PORT
```
and comment
```objc
#define SERVER_URL PROD_SERVER_URL
#define SERVER_URI PROD_SERVER_URI
#define SERVER_PORT PROD_SERVER_PORT
```

To deploy AppCorner on a remote server, I share my experience using AWS servers.

The fast and simple way to build a remote server for development/test/website as [appcorner.it](http://www.appcorner.it/en/) is deploy a BITNAMI vm with [MEAN stack](https://bitnami.com/stack/mean/cloud/amazon).

To build a production server with support to mobile app, I recommend to use a dedicated server for mongodb (with deployd installed to run the dashboard or batch scripts) and a frontend server using [AWS Elastic Beanstalk](http://aws.amazon.com/elasticbeanstalk/getting-started/) fon node.js with autoscaling, nginx (with https enable) and deployd's dashboard disabled.


You prefer [LoopBack](http://loopback.io) as backend, than refer to [How to Migrate an mBaaS: Deployd to LoopBack](http://strongloop.com/strongblog/how-to-migrate-an-mbaas-deployd-to-loopback/)

enjoy!
