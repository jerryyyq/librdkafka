/*
 * librdkafka - Apache Kafka C library
 *
 * Copyright (c) 2016, Magnus Edenhill
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met: 
 * 
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer. 
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution. 
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE 
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
#pragma once


/**
 * @brief Kafka protocol features
 */

/* Message version 1 (MagicByte=1):
 *  + relative offsets (KIP-31)
 *  + timestamps (KIP-32) */
#define RD_KAFKA_FEATURE_MSGVER1    0x1

/* ApiVersionQuery support (KIP-35) */
#define RD_KAFKA_FEATURE_APIVERSION 0x2

 /* >= 0.9: Broker-based Balanced Consumer */
#define RD_KAFKA_FEATURE_BROKER_BALANCED_CONSUMER 0x4

/* >= 0.9: Produce/Fetch ThrottleTime reporting */
#define RD_KAFKA_FEATURE_THROTTLETIME 0x8

/* >= 0.9: SASL (GSSAPI) support */
#define RD_KAFKA_FEATURE_SASL       0x10

/* >= 0.10: SaslMechanismRequest (KIP-43) */
#define RD_KAFKA_FEATURE_SASL_HANDSHAKE 0x20

/* >= 0.8.2.0: Broker-based Group coordinator */
#define RD_KAFKA_FEATURE_BROKER_GROUP_COORD 0x40

/* >= 0.8.2.0: LZ4 compression (with bad and proper HC checksums) */
#define RD_KAFKA_FEATURE_LZ4 0x80





int rd_kafka_get_legacy_ApiVersions (const char *broker_version,
				     struct rd_kafka_ApiVersion **apisp,
				     size_t *api_cntp, const char *fallback);
void rd_kafka_ApiVersions_copy (const struct rd_kafka_ApiVersion *src, size_t src_cnt,
				struct rd_kafka_ApiVersion **dstp, size_t *dst_cntp);
int rd_kafka_features_check (rd_kafka_broker_t *rkb,
			     struct rd_kafka_ApiVersion *broker_apis,
			     size_t broker_api_cnt);

const char *rd_kafka_features2str (int features);
