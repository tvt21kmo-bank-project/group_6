const db = require('../database');

const pankki = {
  getById: function(id, Tila, callback) {
    return db.query('select saldo from tili JOIN kortti ON tili.idTili=kortti.tili_idTili where idKortti=? AND Tila=?', [id, Tila], callback);
  },
  getAll: function(callback) {
    return db.query('select saldo from tili', callback);
   
  },
};
module.exports = pankki;