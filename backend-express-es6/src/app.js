// src/app.js

import express, { Router } from 'express';
import path from 'path'

import {routes} from './routes/index';

let app = express();
let router = Router();

// 设置跨域
app.all('*', (req, res, next) => {
    res.header("Access-Control-Allow-Origin", "*");
    res.header("Access-Control-Allow-Headers", "X-Requested-With");
    res.header("Access-Control-Allow-Methods","PUT,POST,GET,DELETE,OPTIONS");
    res.header("X-Powered-By",' 3.2.1')
    res.header("Content-Type", "application/json;charset=utf-8");
    next();
});

// router.get('/', (req, res, next) => {
//   res.end('Hello World!');
// });
// app.use('/', router);

routes(app);

app.listen(3000, () => {
  console.log('server listening at port 3000...');
});
