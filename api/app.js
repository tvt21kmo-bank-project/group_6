var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');
const helmet = require('helmet');
const cors = require('cors');
var app = express();

app.use(helmet());
app.use(cors());
const dotenv = require('dotenv');
dotenv.config();
const basicAuth = require('express-basic-auth');
app.use(basicAuth( { authorizer: myAuthorizer, authorizeAsync:true, } ))

function myAuthorizer(username, password, cb){
    if(username===process.env.authUser && password ===process.env.authPass){
        return cb(null, true);
    }
    else{
        return cb(null, false);
    }
}

var indexRouter = require('./routes/index');
var usersRouter = require('./routes/users');
var loginRouter = require('./routes/login');
var asiakasRouter = require('./routes/asiakas');
var pankkiRouter = require('./routes/pankki');
/*var loginRouter = require('./routes/login');
var bankRouter = require('./routes/bank');*/

app.use('/', indexRouter);
app.use('/users', usersRouter);


app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use('/login', loginRouter);
app.use('/asiakas', asiakasRouter);
app.use('/pankki', pankkiRouter);
/*app.use('/login', loginRouter);
app.use('/bank', bankRouter);*/

module.exports = app;
