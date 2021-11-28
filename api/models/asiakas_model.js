const db = require('../database');
const bcrypt = require('bcryptjs');

const saltRounds=10;
const user={
 // get: function(callback) {
 //   return db.query('select * from Asiakas', callback);
 // },
  getById: function(id, callback) {         
    return db.query('select Nimi from Asiakas JOIN kortti ON Asiakas.idAsiakas=Kortti.Asiakas_idAsiakas where idKortti=?', [id], callback);         // tasta tulee kortti idlla asiakkaan nimi
  },
  add: function(user, callback) {
    bcrypt.hash(user.pin, saltRounds, function(err, hash) {
      return db.query('insert into kortti (idKortti, pin, Asiakas_idAsiakas, Tili_idTili, Tila) values(?,?,?,?,?)',       // tassaa yritetty kaikkea kummallista
      [user.idKortti, hash, user.Asiakas_idAsiakas, user.Tili_idTili, user.Tila], callback); 
    });
  },/*
  delete: function(id, callback) {
    return db.query('delete from user_table where id_user=?', [id], callback);
  },
  update: function(id, user, callback) {
    bcrypt.hash(user.password, saltRounds, function(err, hash) {
      return db.query('update user_table set username=?, password=? where id_user=?',
      [user.username, hash, id], callback);
    });
  }*/

}
          
module.exports = user;