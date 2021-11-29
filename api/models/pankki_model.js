const db = require('../database');

const pankki = {
  getById: function(id, callback) {
    return db.query('select saldo from tili JOIN kortti ON tili.idTili=kortti.tili_idTili where idKortti=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select saldo from tili', callback);
    //return db.query('select idTilitapahtumat, aika, Tapahtuma, Maara from tilitapahtumat JOIN tili ON tilitapahtumat.Tili_idTili=tili.idTili join kortti on tili.idTili=kortti.tili_idTili where idKortti=?', [id], callback);
  },/*
  nosta: function(postData, callback) {
    return db.query('call nostarahaa(?,?)',
      [postData.idKortti, postData.summa],
      callback
    );
  },
  /*delete: function(id, callback) {
    return db.query('delete from book where id_book=?', [id], callback);
  },
  update: function(id, book, callback) {
    return db.query(
      'update book set name=?,author=?, isbn=? where id_book=?',
      [book.name, book.author, book.isbn, id],
      callback
    );
  }*/
};
module.exports = pankki;