/*
 * Extension to validate the provider token.
 *
 * contrib/oauth_token_validator/oauth_token_validator.c
 */

#include "postgres.h"
#include "fmgr.h"
#include "libpq/auth.h"
#include "libpq/libpq.h"
#include "miscadmin.h"
#include "utils/builtins.h"

PG_MODULE_MAGIC;

void _PG_init(void);


PG_FUNCTION_INFO_V1(oauth_token_validator);

/*
 * Returns the current user's authenticated identity.
 */
Datum
oauth_token_validator(PG_FUNCTION_ARGS)
{
	if (!MyClientConnectionInfo.authn_id)
		PG_RETURN_NULL();

	PG_RETURN_TEXT_P(cstring_to_text(MyClientConnectionInfo.authn_id));
}


static int
OAuthTokenProvider(Port *port, const char* token)
{
	/* fill in provider specific token validation logic */
	/* for now, just say token validation is successful */
	if (token == NULL)
		return STATUS_EOF;

	return STATUS_OK;
}

static const char *OAuthError(Port *port)
{
	return psprintf("OAuth bearer authentication failed for user \"%s\"",
					port->user_name);
}

static OAuthProviderOptions *OAuthReadOptions()
{
	OAuthProviderOptions *oauth_end_points = palloc(sizeof(OAuthProviderOptions));
	oauth_end_points->issuer_url = "https://dev-74019458.okta.com";	
	oauth_end_points->scope = "openid offline_access";
	return oauth_end_points;
}

void
_PG_init(void)
{
	RegistorOAuthProvider(
		"testtokenvalidator",
		OAuthTokenProvider,
		OAuthError,
		OAuthReadOptions
	);
}

/*
 * Module unload callback
 */
void
_PG_fini(void)
{}