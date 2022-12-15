/* contrib/oauth_token_validator/oauth_token_validator--1.0.sql */

-- complain if script is sourced in psql, rather than via CREATE EXTENSION
\echo Use "CREATE EXTENSION oauth_token_validator" to load this file. \quit

CREATE FUNCTION oauth_token_validator() RETURNS text
AS 'MODULE_PATHNAME', 'oauth_token_validator'
LANGUAGE C IMMUTABLE;
